using Microsoft.VisualStudio.TestTools.UnitTesting;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace Fall2015
{
    /// <summary>
    /// Semaphore(n):
    /// - Ref: https://blog.feabhas.com/2009/09/mutex-vs-semaphores-%E2%80%93-part-1-semaphores/
    /// - Controls access to critical section
    /// - It has a max number of threads that can access the critical section at a time 
    /// - Each time a thread tries to access the critical section
    /// 1) It increments a counter and checks for counter > max, if true it goes into wait state as max access reached
    /// 2) else, the thread control is allowed to pass.
    /// 3) A thread after accessing the critical section, releases the resouce by decrementing the counter and
    /// 4) If the counter >= max (ie. some thread is waiting for a release) signals the waiting thread to proceed.
    /// 
    /// ** A binary semaphore is when n == 1
    /// 
    /// Mutex:
    /// - Ref: https://blog.feabhas.com/2009/09/mutex-vs-semaphores-%E2%80%93-part-2-the-mutex/
    /// ** NOTE: A binary semaphore is NOT mutex, because of ownership. A thread which acquires a mutex lock,
    ///    only it can unlock it. 
    /// ** While in a Semaphore, any thread or task can sinal a waiting thread to access the critical section
    /// - Mutex also controls the access to critical section by acquiring a mutal exclusive lock on an object
    ///   thus serializing the access when concurrent threads are accessing the critical resource.
    /// </summary>

    class Semaphore
    {
        private int counter = 0;
        private readonly int max;
        private AutoResetEvent singal = new AutoResetEvent(false);       

        public Semaphore(int max)
        {
            this.max = max;
        }

        public void Enter()
        {
            int current = Interlocked.Increment(ref this.counter);
            if(current > this.max){
                // make the thread to wait.
                singal.WaitOne();
            }

            // else allow the thread to continue (to access the critial resource)
        }

        public void Release()
        {
            int current = Interlocked.Decrement(ref this.counter);
            if (current >= this.max)
            {
                // someone is still waiting on a release, so
                // signal the waiting thread.
                singal.Set();
            }
        }
    }


    [TestClass]
    public class SemaphoreTests
    {
        [TestMethod]
        public void TestSemaphore()
        {
            Semaphore s = new Semaphore(2);
            Task t1 = Task.Factory.StartNew(s.Enter);
            bool t1Result = t1.Wait(TimeSpan.FromSeconds(1));
             // should acquire access
            Assert.IsTrue(t1Result);

            Task t2 = Task.Factory.StartNew(s.Enter);
            bool t2result = t2.Wait(TimeSpan.FromSeconds(2));
            // should acquire access
            Assert.IsTrue(t2result);

            Task t3 = Task.Factory.StartNew(s.Enter);
            // Goes on wait indefinitely untill someone releases and signals
            bool t3Result = t3.Wait(TimeSpan.FromSeconds(3));
            // since t3 wont complete in 3 sec, the wait is going to return with false.
            Assert.IsFalse(t3Result);

            // only max of 2 tasks allowed into the semaphore.
            // we acquired 3 locks, so
            // release 2 semaphore locks for next task t4.
            Task tr1 = Task.Factory.StartNew(s.Release);
            Task tr2 = Task.Factory.StartNew(s.Release);

            // now t4 should acquire access.
            Task t4 = Task.Factory.StartNew(s.Enter);
            bool t4Result = t4.Wait(TimeSpan.FromSeconds(4));
            Assert.IsTrue(t4Result);

        }
    }
}
