package game;

import java.io.Serializable;

public class Hero implements Serializable{
    private final String name;
    private int health;
    private int gold;
    private int resources;
    
    private final Map.Field losingField;
    private final Map.Field friendlyField;
    private final Map.Field winningField;
    private final Runnable jokerAction;

    public Hero(
        String name, 
        int health, 
        int gold, 
        int resources, 
        Map.Field losingField, 
        Map.Field friendlyField, 
        Map.Field winningField, 
        Runnable jokerAction
        ){
            this.name = name;
            this.health = health;
            this.gold = gold;
            this.resources = resources;
            this.losingField = losingField;
            this.friendlyField = friendlyField;
            this.winningField = winningField;
            this.jokerAction = jokerAction;
    }

    public Hero(
        String name, 
        int health, 
        int gold, 
        int resources, 
        Map.Field losingField, 
        Map.Field friendlyField, 
        Map.Field winningField
        ){
            this(name, health, gold, resources, losingField, friendlyField, winningField, (Runnable)null);
    }
    public Hero(
        String name, 
        int health, 
        int gold, 
        int resources, 
        Map.Field losingField, 
        Map.Field friendlyField, 
        Map.Field winningField,
        Character c
        ){
            this.name = name;
            this.health = health;
            this.gold = gold;
            this.resources = resources;
            this.losingField = losingField;
            this.friendlyField = friendlyField;
            this.winningField = winningField;
            switch (c) {
                case 'H':
                    jokerAction = (Runnable & Serializable)() -> {
                        this.health++;
                    };
                    break;
                case 'R':
                    jokerAction = (Runnable & Serializable)() -> {
                        this.resources++;
                    };
                    break;
                case 'M':
                    jokerAction = (Runnable & Serializable)() -> {
                        this.gold++;
                    };
                    break;
                default:
                    jokerAction = null;
                    break;
            }
    }
    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder("");
        sb.append("name: " + name);
        sb.append(" health: " + Integer.toString(health));
        sb.append(" gold: " + Integer.toString(gold));
        sb.append(" resources: " + Integer.toString(resources));
        sb.append(" losingField: " + losingField.toString());
        sb.append(" friendlyField: " + friendlyField.toString());
        sb.append(" winningField: " + winningField.toString());
        if(jokerAction != null)
            sb.append(" joker: " + jokerAction.toString());

        return sb.toString();

    }

    public void processField(Map.Field actualField) {
        if(actualField == losingField){
            health--;
            return;
        }
        if (actualField == friendlyField) {
            resources++;
            return;
        }
        if(actualField == winningField){
            gold++;
            return;
        }
        if(actualField == Map.Field.JOKER && jokerAction != null){
            jokerAction.run();
            return;
        }
    }

    public String getName() {
        return this.name;
    }
    public boolean isEnd(){
        return health <= 0;
    }

}