import java.util.NoSuchElementException;
import java.util.ArrayList;

class Stack {
    ArrayList<Integer> numbers = new ArrayList<Integer>();

    public Stack push (int n) {
        this.numbers.add(n);
        return this;
    }

    public int pop() throws NoSuchElementException {
        if (0 == this.numbers.size()) {
            throw new NoSuchElementException();
        }
        else {
            int lastIndex = this.numbers.size()-1;
            int temp = this.numbers.get(lastIndex);
            this.numbers.remove(lastIndex);
            return temp;
        }
    }

    public boolean empty() {
        return 0 == this.size();
    }

    public int size() {
        return this.numbers.size();
    }
}