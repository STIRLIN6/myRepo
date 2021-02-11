import java.io.*;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        if (args.length < 1) {
            System.err.println("Not enough command line arguments. 1 required.");
        }

        String inputFile = args[0];

        System.out.print("Text to find: ");
        String textToFind = System.console().readLine();

        countAppearances(inputFile, textToFind);
    }

    private static void countAppearances(String inputFile, String textToFind) {
        File in = new File(inputFile);

        try ( Scanner sc = new Scanner(in) ) {
            int count = 0;

            while (sc.hasNextLine() ) {
                String line = sc.nextLine();

                if (line.contains(textToFind)) {
                    ++count;
                }
            }
            System.out.println("'" + textToFind + "' appeared in " +
                count + " lines.");
        } catch (FileNotFoundException e) {
            System.err.println("The file cannot be opened.");
        }
    }
}
