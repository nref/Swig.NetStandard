using NUnit.Framework;

namespace Tests
{
    public class SwigTests
    {
        [Test]
        public void ObjectInitializer_Works()
        {
            var hasTest = new HasTest(new Test { Value = 5 });

            Assert.AreEqual(5, hasTest.GetValue());
        }

        [Test]
        public void Csharp_Calls_Cplusplus()
        {
            var hasTest = new HasTest(new Test());

            hasTest.SetValue(6);
            Assert.AreEqual(6, hasTest.GetValue());
        }

        /// <summary>
        /// Verify that Swig Director enables cross-language inheritance
        /// </summary>
        [Test]
        public void Cplusplus_Calls_Csharp()
        {
            var hasTest = new HasTest(new DerivedTest());

            hasTest.SetValue(4);
            Assert.AreEqual(8, hasTest.GetValue());
        }
    }

    class DerivedTest : Test
    {
        public override void SetValue(int value)
        {
            _myValue = 2 * value;
        }

        public override int GetValue()
        {
            return _myValue;
        }

        private int _myValue = 0;
    }
}