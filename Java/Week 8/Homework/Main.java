import java.util.ArrayList;

import java.io.IOException;

import java.io.FileInputStream;
import java.io.FileOutputStream;

import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;

import java.util.Scanner;

@SuppressWarnings("unchecked")
class Main {
    public static void main (String[] args) {

        ArrayList<Hero> heroes = new ArrayList<Hero>();
        
        // MAP
        int f = 3;
        int l = 3;
        ArrayList<Map> maps = new ArrayList<Map>();
        maps.add(new Map(f, l));
        maps.add(new Map(f, l));
        maps.add(new Map(f, l));

        // HEROES
        if (args.length == 0) {

            heroes.add(new Hero("Ironman", 10, 1000, 50, Map.Field.ROCK_MONSTER, Map.Field.SCISSORS_MONSTER, Map.Field.PAPER_MONSTER, 'H'));
            heroes.add(new Hero("Roniman", 3, 100, 12, Map.Field.PAPER_MONSTER, Map.Field.ROCK_MONSTER, Map.Field.SCISSORS_MONSTER, 'R'));
            heroes.add(new Hero("Onirman", 5, 3, 200, Map.Field.SCISSORS_MONSTER, Map.Field.PAPER_MONSTER, Map.Field.PAPER_MONSTER, 'M'));
        }
        else {
            String file = args[0];

            try (ObjectInputStream is = new ObjectInputStream(new FileInputStream(file))) {
                heroes = (ArrayList<Hero>) is.readObject();
            } catch (ClassNotFoundException | IOException e) {
                e.printStackTrace();
            }
        }

        for (Map m : maps)
        {
            for (int i = 0; i < l; i++) {
                for (int j = 0; j < f; j++) {
                    for (Hero h : heroes) {
                        if (h.health > 0) {
                            h.processField(m.getLevel(i)[j]);
                        }
                    }
                }
            }
            for (Hero h : heroes) {
                System.out.println(h.toString());
            }

            System.out.println("Save? (Type Y, if you want to save, anything else, if don't want to save.)");
            Scanner sc = new Scanner(System.in);
            char c = sc.next().charAt(0);
            if (c == 'Y') {
                System.out.println("filename: ");
                String fileo = System.console().readLine();
                
                try (ObjectOutputStream os = new ObjectOutputStream(new FileOutputStream(fileo))) {
                    os.writeObject(heroes);
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }
    }
}