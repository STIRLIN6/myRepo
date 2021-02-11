class Circle {
	
	double x;
	double y;
	double r;
	
	public void enlarge(double f) {
		this.r *= f;
	}
	
	public double getArea() {
		return Math.PI * r * r;
	}
	
}
