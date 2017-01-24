import java.util.Random;
import java.util.*;
import java.lang.*;

class KMeans {
    public static void main(String[] args) {
        int[] a = { 2, 4, 10, 12, 3, 20, 30, 11, 25 };
        int m1, m2, m1Old, m2Old;
        m1 = new Random().nextInt(a.length);
        do {
            m2 = new Random().nextInt(a.length);
        } while (m1 == m2);

        System.out.println("Means selected are " + m1 + " and " + m2);

        ArrayList<Integer> c1;
        ArrayList<Integer> c2;

        Object[] temp_mean;
        do {
            m1Old = m1;
            m2Old = m2;
            temp_mean = cluster(m1, m2, a);
            // for(Object o: temp_mean)
            //    System.out.println(o);
            m1 = (Integer)(temp_mean[0]);
            m2 = (Integer)(temp_mean[1]);
            c1 = (ArrayList<Integer>)(temp_mean[2]);
            c2 = (ArrayList<Integer>)(temp_mean[3]);
        } while (m1Old != m1 && m2Old != m2);
        System.out.println("Cluster 1: " + c1);
        System.out.println("Cluster 2: " + c2);
    }

    public static Object[] cluster(int m1, int m2, int[] a){
        ArrayList<Integer> c1 = new ArrayList<Integer>();
        ArrayList<Integer> c2 = new ArrayList<Integer>();

        int m1New = 0;
        int m2New = 0;

        for(int e: a) {
            if(Math.abs(e-m1) < Math.abs(e-m2)) {
                // System.out.println("c1:" + e);
                c1.add(e);
                m1New += e;
            } else {
                // System.out.println("c2:" + e);
                c2.add(e);
                m2New += e;
            }
        }

        m1New /= c1.size() != 0 ? c1.size() : 1;
        m2New /= c2.size() != 0 ? c2.size() : 1;

        return new Object[]{m1New, m2New, c1, c2};
    }

}

