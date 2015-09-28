using Microsoft.VisualStudio.TestTools.UnitTesting;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Fall2015
{
    /// <summary>
    /// Ref: http://readyforsoftwareinterview.blogspot.com/2013/04/find-words-in-matrix-of-latters.html
    /// </summary>
    public class FindWordsInMatrixOfLetters
    {
        // time complexity: (-) n^2 * n^2
        internal static string[] Find(char[][] matrix, string[] input)
        {            
            var result = new List<string>();

            // generate a matrix hashset for all chars to count in the matrix.
            // time complexity: (-) n*m
            // space complexity: (-) n*m
            Dictionary<char, int> matrixCharDic = GetMatrixCharDictionary(matrix);

            // for each input word
            // - generate a word hashset of all chars to count
            // - check each char in word hashset has a char in matrix hashset and its count <= matrix char count
            // - if the above condition is true add that word to result.
            // time complexity: (-) x * n
            foreach (string word in input)
            {
                // time complexity: (-) n
                // space complexity: (-) n
                Dictionary<char, int> wordDic = GetWordDictionary(word);

                // time complexity: (-) n
                if (isWordPresentInMatrix(wordDic, matrixCharDic))
                {
                    result.Add(word);
                }
            }

            return result.ToArray();
        }

        // time complexity: (-) n
        private static bool isWordPresentInMatrix(Dictionary<char, int> wordDic, Dictionary<char, int> matrixCharDic)
        {
            foreach (char c in wordDic.Keys)
            {
                int count = wordDic[c];

                if (!matrixCharDic.ContainsKey(c) ||
                    count > matrixCharDic[c])
                {
                    return false;
                }
            }

            return true;
        }

        // time complexity: (-) n
        // space complexity: (-) n
        private static Dictionary<char, int> GetWordDictionary(string word)
        {
            Dictionary<char, int> result = new Dictionary<char, int>();
            foreach (char c in word)
            {
                if (result.ContainsKey(c))
                {
                    result[c] = ++result[c];
                }
                else
                {
                    result[c] = 1;
                }
            }

            return result;
        }

        // time complexity: (-) n*m
        // space complexity: (-) n*m
        private static Dictionary<char, int> GetMatrixCharDictionary(char[][] matrix)
        {
            Dictionary<char, int> result = new Dictionary<char, int>();

            foreach (char[] item in matrix)
            {
                foreach (char c in item)
                {
                    if (result.ContainsKey(c))
                    {
                        result[c] = ++result[c];
                    }
                    else
                    {
                        result[c] = 1;
                    }
                }
            }

            return result;
        }
    }

    [TestClass]
    public class FindWordsInMatrixOfLettersTests
    {
        [TestMethod]
        public void TestFindWordsInMatrixOfLetters()
        {
            char[][] matrix = new char[4][];
            matrix[0] = new[] { 'A', 'G', 'H', 'N' };
            matrix[1] = new[] { 'U', 'L', 'O', 'A' };
            matrix[2] = new[] { 'N', 'M', 'L', 'K' };
            matrix[3] = new[] { 'L', 'B', 'V', 'M' };

            string[] input = new string[] { "ALL", "LOEN" };

            string[] output = FindWordsInMatrixOfLetters.Find(matrix, input);


        }
    }
}
