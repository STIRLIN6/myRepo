import java.lang.IllegalArgumentException;

class Caesar {
    int n;
    
    public Caesar (int n) {
        this.n = n;
    }

    public String cipher (String s) throws IllegalArgumentException {
        
        char[] c = s.toCharArray();
        for (int i = 0; i < c.length; i++)
        {
            if (!Character.isLetter(c[i])) {
                throw new IllegalArgumentException();
            }
            if (Character.isLowerCase(c[i])) {
                //lower
                c[i] = (char)((c[i] - 'a' + this.n) % 26 + 'a');
            }
            else {
                //upper
                c[i] = (char)((c[i] - 'A' + this.n) % 26 + 'A');
            }

            
        }

        return new String(c);
    }

    public String decipher (String s) {
        this.n = 0 - this.n;

        String sr = this.cipher(s);

        this.n = 0 - this.n;

        return sr;
    }
}