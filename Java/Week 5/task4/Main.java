import java.io.*;

public class Main {
    public static void main(String[] args) {
        if (args.length < 2) {
            System.err.println("Not enough command line arguments. 2 required.");
        }

        String inputFile = args[0];
        String outputFile = args[1];

        summarize(inputFile, outputFile);
    }

    private static void summarize(String inputFile, String outputFile) {
        
        File in = new File(inputFile);
        File out = new File(outputFile);

        try (BufferedReader br = new BufferedReader(new FileReader(in));
            PrintWriter pw = new PrintWriter(out) ) {

            String line;
            while ( null != (line = br.readLine()) ) {
                String[] parts = line.split(",");
                int sum = 0;
                for (String number : parts) {
                    int i = Integer.parseInt(number);
                    sum += i;
                }
                pw.println(sum);                
            }
        } catch (IOException e) {
            System.err.println("An IO error occurred.");
        }
        
    }
}
