import java.util.Scanner;
public class base64Encoding {
	
	private static final String BASE64_ALPHABET = 
		"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

	public static String decToBin8Bit(int decimal) {
   		StringBuilder binary = new StringBuilder();
   		while (decimal > 0) {
      			binary.append( decimal % 2);
       			decimal = decimal >> 1;
   		}
   		binary.reverse();

   		while(binary.length() < 8) {
       			binary.insert(0, "0");
   		}
	     	return binary.toString();
	}

	public static StringBuilder mapBitStream(StringBuilder combinedBinary) {
		StringBuilder result = new StringBuilder();
		for (int i = 0; i < combinedBinary.length(); i += 6) {
			String sizeBitChunk = combinedBinary.substring(i, i + 6);

			int base64Index = Integer.parseInt(sizeBitChunk, 2);
			result.append(BASE64_ALPHABET.charAt(base64Index));
		} 

		return result;
	}
	
	public static String encode (String input) {
		if (input == null || input.isEmpty()){
			return "";
		}

		StringBuilder combinedBinary = new StringBuilder();
		for (char ch : input.toCharArray()) {
			//System.out.println("char: "+ch+ " ascii value: "+(int)ch);
			combinedBinary.append( decToBin8Bit( (int)ch ) );
			//System.out.println("8bit binary: "+ binary +" combined bits: "+combinedBinary);
		}
		
		// pad the bitstream with trailing zeros
		while (combinedBinary.length() % 6 != 0) {
			combinedBinary.append("0");
		}

		// map 6 bit chunk 
		StringBuilder encodedResult = mapBitStream(combinedBinary);

		// append = symbol to result
		// check for INPUT.length because we padding rule depends on the OG string 
		int remainder = input.length() % 3;
		if (remainder == 1) {
		       	encodedResult.append("==");
		}
		else if (remainder == 2) {
			encodedResult.append("=");
		}

		return encodedResult.toString();
	}

	public static void main(String args[]) {
		/*Scanner sc = new Scanner(System.in);
		System.out.print("Enter String: ");
		String input = sc.nextLine();
		
		String base64Output = encode(input);
		System.out.println("Base 64 encoded: " + base64Output);
		*/

		String testCases[] = {"Man", "Ma","Cat", "Hello World", "A", ""};
		for (int i = 0; i < testCases.length; i++) {
			String base64Output = encode(testCases[i]);
			System.out.println("Base 64 " + testCases[i] + " encoded is: " + base64Output);
		}	
		//sc.close();
	}
}
