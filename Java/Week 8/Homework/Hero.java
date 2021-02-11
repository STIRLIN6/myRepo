import java.io.Serializable;

class Hero implements Serializable
{
    final String name;
    int health;
    int gold;
    int resources;

    final Map.Field losingField;
    final Map.Field friendlyField;
    final Map.Field winningField;
    final Runnable jokerAction;

    private Character joker;

    public Hero (String name, int health, int gold, int resources, Map.Field losingField, Map.Field friendlyField, Map.Field winningField, Character c) {
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
                        joker = 'H';
                    };
                    break;
                case 'R':
                    jokerAction = (Runnable & Serializable)() -> {
                        this.resources++;
                        joker = 'R';
                    };
                    break;
                case 'M':
                    jokerAction = (Runnable & Serializable)() -> {
                        this.gold++;
                        joker = 'M';
                    };
                    break;
                default:
                    jokerAction = null;
                    break;
            }
    }

    public Hero (String name, int health, int gold, int resources, Map.Field losingField, Map.Field friendlyField, Map.Field winningField, Runnable jokerAction) {
        this.name = name;
        this.health = health;
        this.gold = gold;
        this.resources = resources;

        this.losingField = losingField;
        this.friendlyField = friendlyField;
        this.winningField = winningField;
        this.jokerAction = jokerAction;
    }

    public Hero (String name, int health, int gold, int resources, Map.Field losingField, Map.Field friendlyField, Map.Field winningField) {
        this.name = name;
        this.health = health;
        this.gold = gold;
        this.resources = resources;

        this.losingField = losingField;
        this.friendlyField = friendlyField;
        this.winningField = winningField;
        this.jokerAction = null;
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(name);
        sb.append(" ");
        sb.append(health);
        sb.append(" ");
        sb.append(gold);
        sb.append(" ");
        sb.append(resources);
        sb.append(" ");

        sb.append(losingField);
        sb.append(" ");
        sb.append(friendlyField);
        sb.append(" ");
        sb.append(winningField);

        return sb.toString();
    }

    public void processField(Map.Field actualField) {
        if (actualField == this.losingField) {
            this.health--;
        }
        else if (actualField == this.friendlyField) {
            this.resources++;
        }
        else if (actualField == this.winningField) {
            this.gold++;
        }
        else if (actualField == Map.Field.JOKER) {
            this.jokerAction.run();
        }
    }

    public Character getJokerActionCharacter() {
        return joker;
    }
}