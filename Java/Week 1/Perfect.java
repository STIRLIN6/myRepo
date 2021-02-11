class Perfect {
    public static void main (String[] args) {

        int n = Integer.parseInt(args[0]);

        int sum = 0;
        for (int i = 1; i < n; i++) {
            if (0 == n % i) {
                sum += i;
            }
        }

        if (sum == n) {
            System.out.println("Perfect.");
        }
        else {
            System.out.println("Not perfect.");
        }
    }
}