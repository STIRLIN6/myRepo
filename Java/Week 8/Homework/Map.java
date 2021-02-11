import java.util.Random;

class Map {
    enum Field {
        EMPTY, ROCK_MONSTER, PAPER_MONSTER, SCISSORS_MONSTER, JOKER
    }

    private final Field[][] levels;
    private int l;
    private int f;

    public Map (int l, int f) {
        
        this.l = l;
        this.f = f;

        levels = new Field[l][f];

        for (int i = 0; i < l; i++) {
            for (int j = 0; j < f; j++) {
                Random rand = new Random();
                int r = rand.nextInt(5);
                this.levels[i][j] = Field.values()[r];
            }
        }
    }

    public Field[] getLevel(int n) {

        Field[] fields = new Field[f];

        for (int i = 0; i < f; i++) {
            fields[i] = levels[n][i];
        }

        return fields.clone();
    }
}