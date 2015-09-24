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
    /// Queue property: First In First Out
    /// Stack Property: Last In First Out
    /// </summary>
    class QueueUsingStack
    {
        private Stack<Node> src = new Stack<Node>();
        private Stack<Node> temp = new Stack<Node>();

        public QueueUsingStack()
        {

        }

        public void Push(Node n)
        {
            src.Push(n);
        }

        public Node Pop()
        {
            Node result;
            
            // push all elements from src to temp.
            while (src.Count > 0)
            {
                Node n = src.Pop();
                temp.Push(n);
            }

            // now temp contains the first element added to src
            // pop to get FIFO behaviour
            result = temp.Pop();

            // push back all remaining elements from temp to src
            while(temp.Count > 0){
                Node n = temp.Pop();
                src.Push(n);
            }

            return result;
        }
    }

    [TestClass]
    public class QueueUsingStackTests
    {
        [TestMethod]
        public void TestQueueUsingStack()
        {
            // Queue: First In First Out.
            QueueUsingStack q = new QueueUsingStack();

            Node n1 = new Node(1);
            Node n2 = new Node(2);
            Node n3 = new Node(3);

            q.Push(n1);
            q.Push(n2);
            q.Push(n3);

            Node n11 = q.Pop();
            Assert.IsTrue(n11.Value == n1.Value);

            Node n22 = q.Pop();
            Assert.IsTrue(n22.Value == n2.Value);

            Node n33 = q.Pop();
            Assert.IsTrue(n33.Value == n3.Value);
        }
    }
}
