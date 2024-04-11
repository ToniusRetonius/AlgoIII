import java.util.Scanner;

public class Main {

    public static boolean rEq(String a, String b) {
        if (a.equals(b)) {
            return true;
        }

        if (a.length() == 1 && b.length() == 1) {
            return a.equals(b);
        } else {
            if (a.length() % 2 == 0) {
                int m = a.length() / 2;
                String a1 = a.substring(0, m);
                String a2 = a.substring(m);
                String b1 = b.substring(0, m);
                String b2 = b.substring(m);
                return ((rEq(a1, b2) && rEq(a2, b1)) || (rEq(a1, b1) && rEq(a2, b2)));
            }
            return false;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        String a = scanner.nextLine();
        String b = scanner.nextLine();

        boolean result = rEq(a, b);
        if (result) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }

        scanner.close();
    }
}
