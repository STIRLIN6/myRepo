class Kangaroo {
    private String name;
    private int age;

    public Kangaroo (String name, int age) {
        this.name = name;
        this.age = age;
    }

    public Kangaroo (int age) {
        this.name = null;
        this.age = age;
        System.out.println("4");
    }

    public void display (String country) {
        System.out.println(name);
        System.out.println(country);
        System.out.println(++age);
    }
}