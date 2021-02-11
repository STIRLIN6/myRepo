class Point {
	
	double x;
	double y;
	
	public void move (double dx, double dy) {
		this.x += dx;
		this.y += dy;
	}
	
	public void mirror (double cx, double cy) {
		this.x = 2 * cx - this.x;
		this.y = 2 * cy - this.y;
	}
	
	public void mirror (Point other) {
		this.x = 2 * other.x - this.x;
		this.y = 2 * other.y - this.y;
	}
	
	public double distance(Point other) {
		double a = this.x - other.x;
		double b = this.y - other.y;
		
		return Math.sqrt(a*a + b*b);
	}
}
