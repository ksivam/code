using Microsoft.VisualStudio.TestTools.UnitTesting;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Fall2015
{
    class ReturnContinuousDups
    {
        public ReturnContinuousDups()
        {

        }

        public string ReturnDups(string i)
        {
            string result = string.Empty;
            int len = i.Length;
            char[] c = i.ToCharArray();

            int prev = 0;
            int current = prev + 1;

            // time complexity: (-) n
            while(prev < len && current < len){
                if (c[prev] == c[current])
                {
                    // if prev and current are equal, then we have a dupe
                    result += c[prev];

                    // move prev pointer to the next non dupe value
                    while (prev < len && c[prev] == c[current])
                    {
                        prev += 1;
                    }
                    // now prev points to the next non dupe value, 
                    // advance current to the next of prev pointer
                    current = prev + 1;
                }
                else
                {
                    // else advance the prev and current pointer
                    prev += 1;
                    current = prev + 1;
                }
            }


            return result;
        }
    }

    [TestClass]
    public class ReturnContinuousDupsTests
    {

        [TestMethod]
        public void TestReturnContinuousDups()
        {
            string input = "AABBBHello";
            string expectedResult = "ABl";

            ReturnContinuousDups dups = new ReturnContinuousDups();
            string result = dups.ReturnDups("CAABBD");

            Assert.IsTrue(expectedResult.Equals(result));
        }
    }
}
