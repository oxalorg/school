import java.io.*;
import java.util.ArrayList;
import java.time.LocalTime;
import java.time.Duration;

class GlobalAverage {
    class Clock {
        LocalTime time;
        ArrayList<Duration> avgs = new ArrayList<Duration>();

        Clock(LocalTime t) {
            time = t;
        }

        void resync(LocalTime t) {
            Duration diff = Duration.between(t, time);
            avgs.add(diff);
            System.out.println("DIFF: " + diff);
        }

        LocalTime sync() {
            for(Duration a: avgs) {
                time = time.minus(a.dividedBy(4));
            }
            avgs.clear();
            return time;
        }
    }

    public void run() {
        /* 10.15, 10.10, 10.12, 10.09 */
        /* After 4 iterations */
        ArrayList<Clock> clocks = new ArrayList<Clock>();

        LocalTime referenceTime = LocalTime.of(10, 15, 0);
        clocks.add(new Clock(referenceTime));
        clocks.add(new Clock(LocalTime.of(10, 12, 0)));
        clocks.add(new Clock(LocalTime.of(10, 10, 0)));
        clocks.add(new Clock(LocalTime.of(10, 9, 0)));

        for(int i = 0; i < clocks.size(); i++) {
            Clock sender = clocks.get(i);
            //
            // Advance time for new sender to reach reference
            Duration diff = Duration.between(referenceTime, sender.time);
            for(Clock c: clocks) {
                c.time = c.time.minus(diff);
            }

            for(Clock receiver: clocks) {
                // if (sender != receiver) {
                    receiver.resync(sender.time);
                // }
            }

            System.out.print("Iteration: " + (i+1) + "--> ");
            for(Clock c: clocks) {
                System.out.print(c.time.toString() + " ");
            }
            System.out.println();

        for(Clock c: clocks) {
            System.out.println(c.sync().toString());
        }
    }

    public static void main(String[] args) {
        GlobalAverage ga = new GlobalAverage();
        ga.run();
    }
}
