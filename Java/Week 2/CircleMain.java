class CircleMain {
	public static void main (String[] args) {
		Circle c1 = new Circle();
		c1.r = 3;
		System.out.println("Circle's area: " + c1.getArea());
		
		c1.enlarge(2);
		System.out.println("Circle's area: " + c1.getArea());
	}
}
