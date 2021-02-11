class Factorial {
	
	public static void main ( String[] args ) {
		
		int n = Integer.parseInt(args[0]);
		if (0 == n) {
			System.out.println("0");
		}
		else {
			int fact = 1;
			for (int i = 1; i <= n; i++) {
				fact *= i;
			}
			System.out.println(fact);
		}
	}
	
}
