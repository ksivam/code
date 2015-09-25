using Microsoft.VisualStudio.TestTools.UnitTesting;
using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Fall2015
{
    /// <summary>
    /// Design a cache for translation service with auto deletion.
    /// Ref: http://readyforsoftwareinterview.blogspot.com/2013/04/design-cache-with-auto-deletion.html
    /// Requirements:
    /// 1) The cache has limited size
    /// 2) If cache exceeds its capacity, delete the oldest element
    /// 3) If an elements is accessed, treat that as just being added to the cache.
    /// 
    /// Design:
    /// 1) Use Dictionary to cache the elements
    /// 2) Use LinkedList to keep track of new and old elements (just store the key)
    /// ie
    /// - First element in the list is new.
    /// - Last element in the list is old.
    /// </summary>
    class CacheWithAutoDeletion
    {

        public CacheWithAutoDeletion()
        {
        }
    }

    [TestClass]
    public class CacheWithAutoDeletionTests
    {

        [TestMethod]
        public void TestCacheWithAutoDeletion()
        {

        }
    }
}
