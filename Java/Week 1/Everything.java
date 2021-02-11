class Everything {

	public static void main( String[] args ) {
		
		int a = Integer.parseInt(args[0]);
		int b = Integer.parseInt(args[1]);
		
		System.out.println(a+b);
		System.out.println(Math.abs(a-b));
		System.out.println(a*b);
		if (b != 0) {
			System.out.println((double)a/b);
			System.out.println(a%b);
		}
		
	}

}
