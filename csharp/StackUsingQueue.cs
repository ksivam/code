using Microsoft.VisualStudio.TestTools.UnitTesting;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Fall2015
{
    /// <summary>
    /// Ref: http://readyforsoftwareinterview.blogspot.com/2015/02/implement-queue-fifo-using-2-stacks.html
    /// Stack prop: Last In First Out.
    /// Queue prop: First In First Out.
    /// </summary>
    class StackUsingQueue
    {
        Queue<Node> src = new Queue<Node>();
        Queue<Node> temp = new Queue<Node>();

        public StackUsingQueue()
        {

        }

        public void Push(Node n)
        {
            src.Enqueue(n);
        }

        public Node Pop()
        {
            Node result;
            while(src.Count > 1){
                Node n = src.Dequeue();
                temp.Enqueue(n);
            }

            result = src.Dequeue();

            Queue<Node> t1 = temp;
            temp = src;
            src = t1;

            return result;
        }
    }

    [TestClass]
    public class StackUsingQueueTest
    {
        [TestMethod]
        public void TestStackUsingQueue()
        {
            Node n1 = new Node(1);
            Node n2 = new Node(2);
            Node n3 = new Node(3);

            // Stack prop: Last In First Out
            StackUsingQueue s = new StackUsingQueue();

            s.Push(n1);
            s.Push(n2);
            s.Push(n3);

            Node n33 = s.Pop();
            Assert.IsTrue(n33.Value == n3.Value);

            Node n22 = s.Pop();
            Assert.IsTrue(n22.Value == n2.Value);

            Node n11 = s.Pop();
            Assert.IsTrue(n11.Value == n1.Value);

        }
    }
}
