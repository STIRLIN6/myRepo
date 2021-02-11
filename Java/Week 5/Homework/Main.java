import java.io.*;

class Main {
    public static void main (String args[]) {
        File input = new File(args[0]);
        File output = new File(args[1]);

        try (BufferedReader bf = new BufferedReader(new FileReader(input));
             PrintWriter pw = new PrintWriter(output))
        {
            int number;
            String line;

            while (null != (line = bf.readLine())) {
                
                String[] temp = line.split(" ");
                
                number = Integer.parseInt(temp[0]);

                String lineRest = temp[1];
                
                String[] parts = lineRest.split(",");

                boolean sumIsPossible = false;
                int a = 0;
                int b = 0;

                for (int i = 0; i < parts.length-1; i++)
                {
                    for (int j = i+1; j < parts.length; j++)
                    {
                        if (Integer.parseInt(parts[i]) + Integer.parseInt(parts[j]) == number)
                        {
                            sumIsPossible = true;
                            a = Integer.parseInt(parts[i]);
                            b = Integer.parseInt(parts[j]);
                        }
                    }
                }
                
                pw.print(number + " ");
                if (sumIsPossible) {
                    pw.println(a + " " + b);
                }
                else {
                    pw.println("none");
                }
            }
        }
        catch (IOException e) {
            System.out.println(e.getMessage());
        }
    }
}