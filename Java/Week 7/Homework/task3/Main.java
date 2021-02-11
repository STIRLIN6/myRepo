class Main {
    public static void main (String[] args) {

        if (Adder.add("1", "2").equals("3.0")) {
            System.out.println("Test1");
        }

        if (Adder.add("5.04", "4.96").equals("10.0")) {
            System.out.println("Test2");
        }

        if (Adder.add("three","four").equals("7.0")) {
            System.out.println("Test3");
        }

        if (Adder.add("0b11","0b10").equals("5.0")) {
            System.out.println("Test4");
        }
    }
}