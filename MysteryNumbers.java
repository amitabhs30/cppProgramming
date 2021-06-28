import java.util.Arrays;
 
/**
 * 
 * SaveAs - MysteryNumbers.java
 * 
 * Usage:
 * Compile Class command - javac MysteryNumbers.java
 * Run Class command - java MysteryNumbers <N> <S> <M>
 * 
 * The Class MysteryNumbers.
 * Returns the output on command line.
 */
public class MysteryNumbers {
 
    /**
     * The Class InvalidAnswerException.
     */
    public class InvalidAnswerException extends Exception {
 
        private static final long serialVersionUID = -8795275509806367649L;
 
        public InvalidAnswerException(String errorMessage) {
            super(errorMessage);
        }
 
    }
 
    /**
     * The main method.
     *
     * @param args the arguments
     * @throws InvalidAnswerException the invalid answer exception
     */
    public static void main(String[] args) throws InvalidAnswerException {
        System.out.println("Max Count = " + determineCount(args[0], Integer.parseInt(args[1]), args[2]));
    }
 
    /**
     * Determine count.
     *
     * @param N the n
     * @param S the s
     * @param M the m
     * @return the int
     * @throws InvalidAnswerException the invalid answer exception
     */
    private static int determineCount(final String N, final int S, final String M) throws InvalidAnswerException {
 
        // Normalize both string, as we are doing apple to apple comparison.
 
        final String inputString = normalize(M);
        final String searchString = normalize(N);
 
        final int[] occurance = new int[searchString.length()];
 
        // complexity > n and less < n2, as for second loop we are jumping to next found
        // index.
 
        for (int i = 0; i < searchString.length(); i++) {
 
            int count = 0;
            int lastIndex = 0;
 
            while (lastIndex != -1) {
 
                // increments to the last found index
 
                lastIndex = inputString.indexOf(searchString.charAt(i), lastIndex);
 
                if (lastIndex != -1) {
                    count++;
                    lastIndex += 1;
                }
            }
 
            occurance[i] = count;
        }
 
        int maxCount = Arrays.stream(occurance).min().getAsInt();
 
        // Verify answer
        // Max Count will always be mathematically
        // if string M if of even length, then M/N--> above example -- 6/2 = 3
        // if string M has odd length, LowerBound[M/N] --> 5/2 == 2
        if (maxCount > S / N.length()) {
            throw new MysteryNumbers().new InvalidAnswerException(
                    "MaxCount cannot exceed by length of \"M\"/length of \"N\"");
        }
 
        // Find out minimum element in N X 1 array. Minimum element determines the
        // count.
        return maxCount;
    }
 
    private static String normalize(final String input) {
        // As 2 and 5 are same numbers.
        // And 9 and 7 are same numbers.
        return input.replaceAll("2", "5").replaceAll("9", "6");
    }
}