class ComplexMain {
	public static void main (String[] args) {
		Complex c1 = new Complex();
		c1.re = 6;
		c1.im = -8;
		Complex z = new Complex();
		z.re = 4;
		z.im = 2;

		print(c1);
		print(z);
		c1.div(z);
		print(c1);

		c1.conjugate();
		print(c1);

		c1.re = Math.sqrt(2);
		c1.im = Math.sqrt(2);
		print(c1);

		c1.reciprocate();
		print(c1);
		
		/*c1.re = 1;
		c1.im = 2;
		print(c1);
		
		Complex c2 = new Complex();
		c2.re = 1;
		c2.im = 1;
		c1.add(c2);
		print(c1);
		
		c1.sub(c2);
		print(c1);
		
		c1.mul(c2);
		print(c1);*/
	}
	
	public static void print(Complex c) {
		System.out.println("Valos: " + c.re + " Kepzetes: " + c.im);
	}
}
