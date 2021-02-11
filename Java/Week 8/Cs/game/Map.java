package game;
import java.util.Random;
/**
 * Map
 */
public class Map {

    public enum Field{
        EMPTY,
        ROCK_MONSTER,
        PAPER_MONSTER,
        SCISSORS_MONSTER,
        JOKER;

        private static final int SIZE = values().length;
        private static final Random r = new Random();

        public static Field getRandoomField(){
            return values()[r.nextInt(SIZE)];
        }
    };

    private final Field[][] levels;

    public Map(int n, int m){
            levels = new Field[n][m];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    levels[i][j] = Field.getRandoomField();
                }
            }
    }

    public Field[] getLevel(int n){
        return levels[n].clone();
    }
}
