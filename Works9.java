package utils;

import java.util.Set;
import java.util.TreeSet;

public class LCS {
    private static Set<String> set = new TreeSet<String>();

    public static void main(String[] args) {
        String str1 = "ABCBDAB";
        String str2 = "BDCABA";
        LCS_LENGHT(str1, str2);
        for (String string : set) {
            System.out.println(string);
        }
    }

    public static void LCS_LENGHT(String str1, String str2) {
        int[][] mat = new int[str1.length() + 1][str2.length() + 1];
        for (int i = 0; i <= str1.length(); i++) {
            for (int j = 0; j <= str2.length(); j++) {
                if(i==0||j==0)
                    mat[i][j]=0;
                else if (str1.charAt(i-1) == str2.charAt(j-1)) {
                    mat[i][j] = mat[i -1][j - 1] + 1;
                } else {
                    mat[i][j]=Math.max(mat[i - 1][j] , mat[i][j - 1] );
                }
            }
        }
        PRINT_LCS_ALL(mat, str1, str2, str1.length(), str2.length(),new String());
    }

    //因为两个字符串的最长公共子序列不唯一，此方法返回全部的公共子序列
    private static void PRINT_LCS_ALL(int[][] mat, String str1, String str2,
                                      int m, int n, String str) {
        if (m == 0 || n == 0) {
            if (str.length()!= 0)
                set.add(new StringBuilder(str).reverse().toString());
            return;
        }

        if (str1.charAt(m-1)== str2.charAt(n-1)) {
            PRINT_LCS_ALL(mat, str1, str2, m - 1, n - 1,
                    str+str1.charAt(m-1));
        } else if (mat[m][n - 1] > mat[m - 1][n]) {
            PRINT_LCS_ALL(mat, str1, str2, m, n - 1, str);
        } else if (mat[m][n - 1] < mat[m - 1][n]) {
            PRINT_LCS_ALL(mat, str1, str2, m - 1, n, str);
        } else {
            PRINT_LCS_ALL(mat, str1, str2, m, n - 1, str);
            PRINT_LCS_ALL(mat, str1, str2, m - 1, n, str);
        }
    }
}
