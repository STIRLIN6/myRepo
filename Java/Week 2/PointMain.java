class PointMain {
	public static void main (String[] args) {
		Point p1 = new Point();
		p1.x = 0;
		p1.y = 0;
		
		print(p1);
		
		p1.move(1, 1);
		print(p1);
		
		p1.mirror(0, 0);
		print(p1);
		
		Point p2 = new Point();
		p2.x = 0;
		p2.y = 0;
		
		p1.mirror(p2);
		print(p1);
		
		Point p3 = new Point();
		p3.x = 3;
		p3.y = 3;
		
		System.out.println("Distance of p1 and p3: " + p1.distance(p3));
	}
	
	public static void print (Point p) {
		System.out.println("Coordinates: " + p.x + " " + p.y);
	}
}
