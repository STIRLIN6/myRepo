package datastructures.mutable;

import java.io.IOException;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.DataOutputStream;
import java.io.FileOutputStream;

import datastructures.Month;
import static datastructures.Month.*;

public class SetOfMonths {
	private short bitmask;

	private SetOfMonths( short bitmask ){
		this.bitmask = bitmask;
	}

	public SetOfMonths add( Month month ){
		int position = month.ordinal();
		bitmask |= (1 << position);
		return this;
	}

	public SetOfMonths add( String[] months ){
		for( String month: months ){
			int position = Month.valueOf(month).ordinal();
			bitmask |= (1 << position);
		}
		return this;
	}

	public boolean contains( Month month ){
		return (bitmask >> month.ordinal()) % 2 != 0;
	}

	public SetOfMonths remove( Month month ){
		int position = month.ordinal();
		int oneAtPosition = (1 << position);
		int zeroAtPosition = (-1) ^ oneAtPosition;
		//may:  0000 0001 0000
		//komp: 1111 1111 1110
		//      1111 1110 1111
		bitmask &= zeroAtPosition;
		return this;
	}

	public String toString(){
		StringBuilder sb = new StringBuilder("{");
		short s = bitmask;
		for( Month month: Month.values() ){
			if( s % 2 != 0 ){
				sb.append(month);
				sb.append(',');
			}
			s /= 2;
		}
		int len = sb.length();
		if( len > 1 ){
			sb.setCharAt(len-1,'}');
		} else {
			sb.append('}');
		}
		return sb.toString();
	}

	public static SetOfMonths empty(){
	       	return new SetOfMonths((short)0);
	}

	public static SetOfMonths of( Month... months ){
		short bitmask = 0;
		for( Month month: months ){
			int position = month.ordinal();
			bitmask |= (1 << position);
		}
		return new SetOfMonths(bitmask);
	}

	public static SetOfMonths readFromFile( String fname ){
		try( DataInputStream in = new DataInputStream(new FileInputStream(fname)) ){
			return new SetOfMonths( in.readShort() );
		} catch( IOException e ){
			e.printStackTrace();
			return null;
		}
	}

	public void writeToFile( String fname ) throws IOException {
		try( DataOutputStream out = new DataOutputStream(new FileOutputStream(fname)) ){
			out.writeShort( bitmask );
		}
	}

	public static void main( String[] args ){
		System.out.println(empty().add(January).add(March).remove(March).add(June));
		System.out.println(empty());

		SetOfMonths example = SetOfMonths.of(April, July, February).remove(July).remove(April).add(July).add(new String[]{"September", "October", "May"});
		System.out.println(example);
		try {
			example.writeToFile("example.dat");
			SetOfMonths example2 = SetOfMonths.readFromFile("example.dat");
			System.out.println(example2);
		} catch( java.io.IOException e ){
			System.err.println("Could not write set to file.");
		}
	}
}
