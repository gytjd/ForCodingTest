
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        sc.nextLine(); 

        Set<String> set = new HashSet<>(); 

        for (int i = 0; i < N; i++) {
            set.add(sc.nextLine());
        }


        List<String> words = new ArrayList<>(set);


        Collections.sort(words, Main::customSort);


        for (String word : words) {
            System.out.println(word);
        }
    }

    public static int customSort(String a, String b) {

        if (a.length() != b.length()) {
            return a.length() - b.length();
        } else {
            return a.compareTo(b);
        }
    }
}
