import java.util.Scanner;

public class Tower_Defense {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n, m, k, w;
        n = scanner.nextInt();
        m = scanner.nextInt();
        k = scanner.nextInt();
        w = scanner.nextInt();

        int[] p = new int[m];
        int[] h = new int[m];
        int[] t = new int[k];

        for (int i = 0; i < m; ++i) {
            p[i] = scanner.nextInt();
        }
        for (int i = 0; i < m; ++i) {
            h[i] = scanner.nextInt();
        }
        for (int i = 0; i < k; ++i) {
            t[i] = scanner.nextInt();
        }

        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < m; ++j) {
                if (t[i] - w <= p[j] && p[j] <= t[i] + w) {
                    if (h[j] != 0) {
                        --h[j];
                        break;
                    }
                }
            }
        }

        int sum = 0;
        for (int e : h) {
            sum += e;
        }
        System.out.println(sum);
    }
}
