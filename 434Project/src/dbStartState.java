public class dbStartState implements State {
    public void doAction(Context context) {

        System.out.println("DB connecting");
        context.setState(this);
    }

    @Override
    public String toString() {
        GuiManager.setConnectionStat("DB is connecting");
        return "DB is connecting";
    }
}
