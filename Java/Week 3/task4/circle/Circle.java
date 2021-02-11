

package circle;


public class Circle {
    public circle.utils.Point center;
    public double radius;

    public void enlarge(double f) {
        radius *= f;
    }

    public double getArea() {
        return Math.PI * radius * radius;
    }

    public String toString() {
        return "(" + center.x + "," + center.y + "), r = " + radius;
    }
}

