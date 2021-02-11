

package circle;


public class Main {
    public static void main(String[] args) {
        Circle c1 = new Circle();
        c1.center = new circle.utils.Point(); // ez így nyeh -> kell konstruktor
        c1.center.x = 3;
        c1.center.y = 5;
        c1.radius = 10;
        System.out.println(c1);
        c1.enlarge(3);
        System.out.println(c1);
    }
}