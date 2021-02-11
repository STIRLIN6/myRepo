package datastructures.immutable;

import datastructures.Month;
import static datastructures.Month.*;

public final class SetOfMonths {
	private final short bitmask;

	private SetOfMonths( short bitmask ){
		this.bitmask = bitmask;
	}

	public SetOfMonths add( Month month ){
		int position = month.ordinal();
		return new SetOfMonths( (short)(bitmask | (1 << position)) );
	}

	public boolean contains( Month month ){
		return (bitmask >> month.ordinal()) % 2 != 0;
	}

	public SetOfMonths remove( Month month ){
		int position = month.ordinal();
		int oneAtPosition = (1 << position);
		int zeroAtPosition = (-1) ^ oneAtPosition;
		return new SetOfMonths( (short)(bitmask & zeroAtPosition) );
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

	public final static SetOfMonths empty = new SetOfMonths((short)0);

	public static SetOfMonths of( Month... months ){
		short bitmask = 0;
		for( Month month: months ){
			int position = month.ordinal();
			bitmask |= (1 << position);
		}
		return new SetOfMonths(bitmask);
	}

	public static void main( String[] args ){
		System.out.println(empty.add(January).add(March).remove(March).add(June));
		System.out.println(empty);
		System.out.println(SetOfMonths.of(April, July, February).remove(July).remove(April).add(July));
	}
}
