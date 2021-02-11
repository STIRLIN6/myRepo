class Line {
	// ax + by = c
	double a, b, c;
	
	public boolean contains(Point p) {
		return a*p.x + b*p.y == c;
	}
	
	// meredekseg azonos
	public boolean isParallelWith(Line other) {
		return this.a * other.b == this.p * other.a;
	}
	
	public boolean isOrthogonalTo(Line other) {
		return this.a * other.a + this.b * other.b == 0;
	}
}
