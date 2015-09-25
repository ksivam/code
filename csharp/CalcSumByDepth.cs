using Microsoft.VisualStudio.TestTools.UnitTesting;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Fall2015
{
    /// <summary>
    /// Ref: http://readyforsoftwareinterview.blogspot.com/2015/02/calculate-sum-of-nested-list-of-int.html
    /// Given a nested list of array, calc the sum by depth
    /// Example: {4, {6,3}} = {4 * 1 + {6 * 2 + 3 * 2}}
    /// Example: {2, {4, {7,8}}} = {2 * 1 + {4 * 2 + {7 * 3 + 8 * 3}}}
    /// Complexity: (-)n
    /// </summary>
    class CalcSumByDepth
    {
        public CalcSumByDepth()
        {

        }

        public int Sum(Node node)
        {
            return this.SumDepth(node, 1);
        }

        private int SumDepth(Node current, int depth)
        {
            // base case
            if (current == null)
            {
                return 0;
            }

            // calc the product of current value and depth
            int currentSum = current.Value * depth;

            // calc the left subtree sum by passing left subtree and depth + 1
            int leftSum = this.SumDepth(current.Left, depth + 1);

            // calc the right subtree sum by passing right subtree and depth + 1
            int rightSum = this.SumDepth(current.Right, depth + 1);

            return currentSum + leftSum + rightSum;
        }
    }

    [TestClass]
    public class CalcSumByDepthTests
    {
        [TestMethod]
        public void TestCalcSumByDepth()
        {
            CalcSumByDepth s = new CalcSumByDepth();

            // test 1: {1,{2,3}} = 1 * 1 + 2 * 2 + 3 * 2 = 11
            Node n1 = this.Case1();
            int r1 = s.Sum(n1);
            Assert.IsTrue(r1 == 11);

            // test 2: {1, {2, {3, 4}}} = 1 * 1 + 2 * 2 + 3 * 3 + 4 * 3 = 26
            Node n2 = this.Case2();
            int r2 = s.Sum(n2);
            Assert.IsTrue(r2 == 26);

        }

        private Node Case1()
        {
            Node n1 = new Node(1);
            n1.Left = new Node(2);
            n1.Right = new Node(3);

            return n1;
        }

        private Node Case2()
        {
            Node n2 = new Node(2);
            n2.Left = new Node(3);
            n2.Right = new Node(4);

            Node n1 = new Node(1);
            n1.Left = n2;

            return n1;
        }
    }
}
