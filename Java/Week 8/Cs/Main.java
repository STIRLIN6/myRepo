import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.ArrayList;
import java.util.Scanner;

import game.*;
@SuppressWarnings("unchecked")
public class Main {
    public static void main(String[] args) {

        System.out.println("Enter the number of levels: ");
        int n = Integer.parseInt(System.console().readLine());
        System.out.println("Enter the number of fields: ");
        int fields = Integer.parseInt(System.console().readLine());
        Map m = new Map(n, fields);
        ArrayList<Hero> heroes = new ArrayList<Hero>();
        String file = "";
        if(args.length == 0) {
            heroes.add(
                new Hero(
                    "test1", 3, 0, 0,
                    Map.Field.ROCK_MONSTER,
                    Map.Field.PAPER_MONSTER,
                    Map.Field.SCISSORS_MONSTER,
                    'M'
                ));
            heroes.add(
                new Hero(
                    "test2", 3, 0, 0,
                    Map.Field.PAPER_MONSTER,
                    Map.Field.ROCK_MONSTER,
                    Map.Field.SCISSORS_MONSTER,
                    'H'
                )
            );
        }
        else{
            file = args[0];
            try (ObjectInputStream ois = new ObjectInputStream(new FileInputStream(file))) {
                heroes = (ArrayList<Hero>) ois.readObject();
            } catch (ClassNotFoundException | IOException e) {
                e.printStackTrace();
            }
        }

        //test
        for (int i = 0; i < 3;++i){
            for (Map.Field x : m.getLevel(i)) {
                System.out.println("level: " + i + " " + x);
            }
        }

        System.out.println("heroes:");
        for(Hero h : heroes)
            System.out.println("\t" + h.toString());

        int i = 0;
        for (; i < n; i++) {
            System.out.println("level: " + i);
            hero:
            for(Hero h : heroes){
                if(h.isEnd())
                    continue hero;
                Map.Field[] level = m.getLevel(i);
                for (Map.Field x : level){
                    h.processField(x);
                }
                System.out.println("\t" + h.toString());

                if(h.isEnd()){
                    System.out.println(h.getName() + " lost at lvl: " + i);
                }
            }

            System.out.println("Do you want to save the current state of the game?(Y/n) default value: n");
            Scanner sc = new Scanner(System.in);
            char c = sc.next().charAt(0);
            if(c == 'Y' || c == 'y'){
                System.out.println("Save as: ");
                String out = System.console().readLine();
                try (ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream(out))) {
                    oos.writeObject(heroes);
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }

        for(Hero h : heroes)
            if(!h.isEnd())
                System.out.println(h.getName() + " Won!");
        /*

*/

    }
}