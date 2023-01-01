import java.util.Scanner;

public class Main {
    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);

        String s = in.nextLine();
        int[] frqLower = new int[26];
        int[] frqUpper = new int[26];
        boolean lower = false, upper = false;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) >= 'a' && s.charAt(i) <= 'z') {
                frqLower[s.charAt(i) - 'a']++;
                lower = true;
            }
            if (s.charAt(i) >= 'A' && s.charAt(i) <= 'Z') {
                frqUpper[s.charAt(i) - 'A']++;
                upper = true;
            }
        }

        boolean ok = lower & upper;
        for (int i = 0; i < 26; i++) {
            if (frqLower[i] > 1) ok = false;
            if (frqUpper[i] > 1) ok = false;
        }

        System.out.println((ok ? "Yes" : "No"));
        in.close();
    }
}