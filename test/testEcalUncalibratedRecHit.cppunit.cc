/* Unit test for EcalUncalibratedRecHit
   Konstantinos Theofilatos', Oct 2011

 */

#include <cppunit/extensions/HelperMacros.h>
#include "DataFormats/EcalRecHit/interface/EcalRecHit.h"
#include "DataFormats/EcalRecHit/interface/EcalUncalibratedRecHit.h"
#include "DataFormats/EcalDetId/interface/EBDetId.h"

class testEcalUncalibratedRecHit: public CppUnit::TestFixture
{
  CPPUNIT_TEST_SUITE(testEcalUncalibratedRecHit);
  CPPUNIT_TEST(testOne);
  CPPUNIT_TEST_SUITE_END();

public:
  void setUp(){}
  void tearDown(){}
  void print(uint32_t k){for(int i=31;i>=0;i--){std::cout<< (((0x1<<i) & k )!=0);} std::cout << std::endl;

}

  void testOne();

};

///registration of the test so that the runner can find it
CPPUNIT_TEST_SUITE_REGISTRATION(testEcalUncalibratedRecHit);

void testEcalUncalibratedRecHit::testOne(){
  
  std::cout << std::endl;
  std::cout << "testing the EcalUncalibratedRecHit " << std::endl;
 
  EcalUncalibratedRecHit urh;

  std::cout << "initial status" << std::endl;
  print(urh.flags());


  urh.setAmplitude(17.3); CPPUNIT_ASSERT(urh.amplitude()==17.3);
  urh.setPedestal(12.35); CPPUNIT_ASSERT(urh.pedestal()==12.35);
    

  urh.setOutOfTimeEnergy(230.63);
  float outOfTimeEnergy_init = urh.outOfTimeEnergy();
  std::cout<< "setting some outOfTimeEnergy = " << urh.outOfTimeEnergy() << std::endl;
  print(urh.flags());

  urh.setOutOfTimeChi2(31.63);
  float outOfTimeChi2_init = urh.outOfTimeChi2();
  std::cout<< "setting some outOfTimeChi2 = " << urh.outOfTimeChi2() << std::endl;
  print(urh.flags());


  std::cout << "start setting flagBits" << std::endl;
  print(urh.flags());
  std::cout << "urh.checkFlag(EcalUncalibratedRecHit::kGood) = "  <<  urh.checkFlag(EcalUncalibratedRecHit::kGood) << std::endl;
  std::cout << "urh.checkFlag(EcalUncalibratedRecHit::kPoorReco) = "  <<  urh.checkFlag(EcalUncalibratedRecHit::kPoorReco) << std::endl;
  std::cout << "urh.checkFlag(EcalUncalibratedRecHit::kSaturated) = "  <<  urh.checkFlag(EcalUncalibratedRecHit::kSaturated) << std::endl;
  std::cout << "urh.checkFlag(EcalUncalibratedRecHit::kOutOfTime) = "  <<  urh.checkFlag(EcalUncalibratedRecHit::kOutOfTime) << std::endl;
  std::cout<<"urh.checkFlag(EcalUncalibratedRecHit::kLeadingEdgeRecovered) = "<<urh.checkFlag(EcalUncalibratedRecHit::kLeadingEdgeRecovered)<<std::endl;
  CPPUNIT_ASSERT(urh.checkFlag(EcalUncalibratedRecHit::kGood));
  CPPUNIT_ASSERT(!urh.checkFlag(EcalUncalibratedRecHit::kPoorReco));
  CPPUNIT_ASSERT(!urh.checkFlag(EcalUncalibratedRecHit::kSaturated));
  CPPUNIT_ASSERT(!urh.checkFlag(EcalUncalibratedRecHit::kOutOfTime));
  CPPUNIT_ASSERT(!urh.checkFlag(EcalUncalibratedRecHit::kLeadingEdgeRecovered));
  CPPUNIT_ASSERT(outOfTimeEnergy_init ==  urh.outOfTimeEnergy());
  CPPUNIT_ASSERT(outOfTimeChi2_init ==  urh.outOfTimeChi2());

  std::cout << "setting EcalUncalibratedRecHit::kPoorReco" << std::endl;
  urh.setFlagBit(EcalUncalibratedRecHit::kPoorReco);// 
  print(urh.flags());
  std::cout << "urh.checkFlag(EcalUncalibratedRecHit::kGood) = "  <<  urh.checkFlag(EcalUncalibratedRecHit::kGood) << std::endl;
  std::cout << "urh.checkFlag(EcalUncalibratedRecHit::kPoorReco) = "  <<  urh.checkFlag(EcalUncalibratedRecHit::kPoorReco) << std::endl;
  std::cout << "urh.checkFlag(EcalUncalibratedRecHit::kSaturated) = "  <<  urh.checkFlag(EcalUncalibratedRecHit::kSaturated) << std::endl;
  std::cout << "urh.checkFlag(EcalUncalibratedRecHit::kOutOfTime) = "  <<  urh.checkFlag(EcalUncalibratedRecHit::kOutOfTime) << std::endl;
  std::cout<<"urh.checkFlag(EcalUncalibratedRecHit::kLeadingEdgeRecovered) = "<<urh.checkFlag(EcalUncalibratedRecHit::kLeadingEdgeRecovered)<<std::endl;
  CPPUNIT_ASSERT(!urh.checkFlag(EcalUncalibratedRecHit::kGood));
  CPPUNIT_ASSERT(urh.checkFlag(EcalUncalibratedRecHit::kPoorReco));
  CPPUNIT_ASSERT(!urh.checkFlag(EcalUncalibratedRecHit::kSaturated));
  CPPUNIT_ASSERT(!urh.checkFlag(EcalUncalibratedRecHit::kOutOfTime));
  CPPUNIT_ASSERT(!urh.checkFlag(EcalUncalibratedRecHit::kLeadingEdgeRecovered));
  CPPUNIT_ASSERT(outOfTimeEnergy_init ==  urh.outOfTimeEnergy());
  CPPUNIT_ASSERT(outOfTimeChi2_init ==  urh.outOfTimeChi2());

  std::cout << "setting EcalUncalibratedRecHit::kOutOfTime" << std::endl;
  urh.setFlagBit(EcalUncalibratedRecHit::kOutOfTime);// 
  print(urh.flags());
  std::cout << "urh.checkFlag(EcalUncalibratedRecHit::kGood) = "  <<  urh.checkFlag(EcalUncalibratedRecHit::kGood) << std::endl;
  std::cout << "urh.checkFlag(EcalUncalibratedRecHit::kPoorReco) = "  <<  urh.checkFlag(EcalUncalibratedRecHit::kPoorReco) << std::endl;
  std::cout << "urh.checkFlag(EcalUncalibratedRecHit::kSaturated) = "  <<  urh.checkFlag(EcalUncalibratedRecHit::kSaturated) << std::endl;
  std::cout << "urh.checkFlag(EcalUncalibratedRecHit::kOutOfTime) = "  <<  urh.checkFlag(EcalUncalibratedRecHit::kOutOfTime) << std::endl;
  std::cout<<"urh.checkFlag(EcalUncalibratedRecHit::kLeadingEdgeRecovered) = "<<urh.checkFlag(EcalUncalibratedRecHit::kLeadingEdgeRecovered)<<std::endl;
  CPPUNIT_ASSERT(!urh.checkFlag(EcalUncalibratedRecHit::kGood));
  CPPUNIT_ASSERT(urh.checkFlag(EcalUncalibratedRecHit::kPoorReco));
  CPPUNIT_ASSERT(!urh.checkFlag(EcalUncalibratedRecHit::kSaturated));
  CPPUNIT_ASSERT(urh.checkFlag(EcalUncalibratedRecHit::kOutOfTime));
  CPPUNIT_ASSERT(!urh.checkFlag(EcalUncalibratedRecHit::kLeadingEdgeRecovered));
  CPPUNIT_ASSERT(outOfTimeEnergy_init ==  urh.outOfTimeEnergy());
  CPPUNIT_ASSERT(outOfTimeChi2_init ==  urh.outOfTimeChi2());


  std::cout << "setting EcalUncalibratedRecHit::kGood" << std::endl;
  urh.setFlagBit(EcalUncalibratedRecHit::kGood);// 
  print(urh.flags());
  std::cout << "urh.checkFlag(EcalUncalibratedRecHit::kGood) = "  <<  urh.checkFlag(EcalUncalibratedRecHit::kGood) << std::endl;
  std::cout << "urh.checkFlag(EcalUncalibratedRecHit::kPoorReco) = "  <<  urh.checkFlag(EcalUncalibratedRecHit::kPoorReco) << std::endl;
  std::cout << "urh.checkFlag(EcalUncalibratedRecHit::kSaturated) = "  <<  urh.checkFlag(EcalUncalibratedRecHit::kSaturated) << std::endl;
  std::cout << "urh.checkFlag(EcalUncalibratedRecHit::kOutOfTime) = "  <<  urh.checkFlag(EcalUncalibratedRecHit::kOutOfTime) << std::endl;
  std::cout<<"urh.checkFlag(EcalUncalibratedRecHit::kLeadingEdgeRecovered) = "<<urh.checkFlag(EcalUncalibratedRecHit::kLeadingEdgeRecovered)<<std::endl;
  CPPUNIT_ASSERT(urh.checkFlag(EcalUncalibratedRecHit::kGood));
  CPPUNIT_ASSERT(!urh.checkFlag(EcalUncalibratedRecHit::kPoorReco));
  CPPUNIT_ASSERT(!urh.checkFlag(EcalUncalibratedRecHit::kSaturated));
  CPPUNIT_ASSERT(!urh.checkFlag(EcalUncalibratedRecHit::kOutOfTime));
  CPPUNIT_ASSERT(!urh.checkFlag(EcalUncalibratedRecHit::kLeadingEdgeRecovered));
  CPPUNIT_ASSERT(outOfTimeEnergy_init ==  urh.outOfTimeEnergy());
  CPPUNIT_ASSERT(outOfTimeChi2_init ==  urh.outOfTimeChi2());

  std::cout << "setting EcalUncalibratedRecHit::kLeadingEdgeRecovered" << std::endl;
  urh.setFlagBit(EcalUncalibratedRecHit::kLeadingEdgeRecovered);// 
  print(urh.flags());
  std::cout << "urh.checkFlag(EcalUncalibratedRecHit::kGood) = "  <<  urh.checkFlag(EcalUncalibratedRecHit::kGood) << std::endl;
  std::cout << "urh.checkFlag(EcalUncalibratedRecHit::kPoorReco) = "  <<  urh.checkFlag(EcalUncalibratedRecHit::kPoorReco) << std::endl;
  std::cout << "urh.checkFlag(EcalUncalibratedRecHit::kSaturated) = "  <<  urh.checkFlag(EcalUncalibratedRecHit::kSaturated) << std::endl;
  std::cout << "urh.checkFlag(EcalUncalibratedRecHit::kOutOfTime) = "  <<  urh.checkFlag(EcalUncalibratedRecHit::kOutOfTime) << std::endl;
  std::cout<<"urh.checkFlag(EcalUncalibratedRecHit::kLeadingEdgeRecovered) = "<<urh.checkFlag(EcalUncalibratedRecHit::kLeadingEdgeRecovered)<<std::endl;
  CPPUNIT_ASSERT(!urh.checkFlag(EcalUncalibratedRecHit::kGood));
  CPPUNIT_ASSERT(!urh.checkFlag(EcalUncalibratedRecHit::kPoorReco));
  CPPUNIT_ASSERT(!urh.checkFlag(EcalUncalibratedRecHit::kSaturated));
  CPPUNIT_ASSERT(!urh.checkFlag(EcalUncalibratedRecHit::kOutOfTime));
  CPPUNIT_ASSERT(urh.checkFlag(EcalUncalibratedRecHit::kLeadingEdgeRecovered));
  CPPUNIT_ASSERT(outOfTimeEnergy_init ==  urh.outOfTimeEnergy());
  CPPUNIT_ASSERT(outOfTimeChi2_init ==  urh.outOfTimeChi2());
  CPPUNIT_ASSERT(!urh.isSaturated());

  std::cout << "setting EcalUncalibratedRecHit::kSaturated" << std::endl;
  urh.setFlagBit(EcalUncalibratedRecHit::kSaturated);// 
  print(urh.flags());
  std::cout << "urh.checkFlag(EcalUncalibratedRecHit::kGood) = "  <<  urh.checkFlag(EcalUncalibratedRecHit::kGood) << std::endl;
  std::cout << "urh.checkFlag(EcalUncalibratedRecHit::kPoorReco) = "  <<  urh.checkFlag(EcalUncalibratedRecHit::kPoorReco) << std::endl;
  std::cout << "urh.checkFlag(EcalUncalibratedRecHit::kSaturated) = "  <<  urh.checkFlag(EcalUncalibratedRecHit::kSaturated) << std::endl;
  std::cout << "urh.checkFlag(EcalUncalibratedRecHit::kOutOfTime) = "  <<  urh.checkFlag(EcalUncalibratedRecHit::kOutOfTime) << std::endl;
  std::cout<<"urh.checkFlag(EcalUncalibratedRecHit::kLeadingEdgeRecovered) = "<<urh.checkFlag(EcalUncalibratedRecHit::kLeadingEdgeRecovered)<<std::endl;
  CPPUNIT_ASSERT(!urh.checkFlag(EcalUncalibratedRecHit::kGood));
  CPPUNIT_ASSERT(!urh.checkFlag(EcalUncalibratedRecHit::kPoorReco));
  CPPUNIT_ASSERT(urh.checkFlag(EcalUncalibratedRecHit::kSaturated));
  CPPUNIT_ASSERT(!urh.checkFlag(EcalUncalibratedRecHit::kOutOfTime));
  CPPUNIT_ASSERT(urh.checkFlag(EcalUncalibratedRecHit::kLeadingEdgeRecovered));
  CPPUNIT_ASSERT(outOfTimeEnergy_init ==  urh.outOfTimeEnergy());
  CPPUNIT_ASSERT(outOfTimeChi2_init ==  urh.outOfTimeChi2());
  CPPUNIT_ASSERT(urh.isSaturated());


  std::cout << "setting EcalUncalibratedRecHit::kOutOfTime" << std::endl;
  urh.setFlagBit(EcalUncalibratedRecHit::kOutOfTime);// 
  print(urh.flags());
  std::cout << "urh.checkFlag(EcalUncalibratedRecHit::kGood) = "  <<  urh.checkFlag(EcalUncalibratedRecHit::kGood) << std::endl;
  std::cout << "urh.checkFlag(EcalUncalibratedRecHit::kPoorReco) = "  <<  urh.checkFlag(EcalUncalibratedRecHit::kPoorReco) << std::endl;
  std::cout << "urh.checkFlag(EcalUncalibratedRecHit::kSaturated) = "  <<  urh.checkFlag(EcalUncalibratedRecHit::kSaturated) << std::endl;
  std::cout << "urh.checkFlag(EcalUncalibratedRecHit::kOutOfTime) = "  <<  urh.checkFlag(EcalUncalibratedRecHit::kOutOfTime) << std::endl;
  std::cout<<"urh.checkFlag(EcalUncalibratedRecHit::kLeadingEdgeRecovered) = "<<urh.checkFlag(EcalUncalibratedRecHit::kLeadingEdgeRecovered)<<std::endl;
  CPPUNIT_ASSERT(!urh.checkFlag(EcalUncalibratedRecHit::kGood));
  CPPUNIT_ASSERT(!urh.checkFlag(EcalUncalibratedRecHit::kPoorReco));
  CPPUNIT_ASSERT(urh.checkFlag(EcalUncalibratedRecHit::kSaturated));
  CPPUNIT_ASSERT(urh.checkFlag(EcalUncalibratedRecHit::kOutOfTime));
  CPPUNIT_ASSERT(urh.checkFlag(EcalUncalibratedRecHit::kLeadingEdgeRecovered));
  CPPUNIT_ASSERT(outOfTimeEnergy_init ==  urh.outOfTimeEnergy());
  CPPUNIT_ASSERT(outOfTimeChi2_init ==  urh.outOfTimeChi2());

  std::cout << "setting EcalUncalibratedRecHit::kPoorReco" << std::endl;
  urh.setFlagBit(EcalUncalibratedRecHit::kPoorReco);// 
  print(urh.flags());
  std::cout << "urh.checkFlag(EcalUncalibratedRecHit::kGood) = "  <<  urh.checkFlag(EcalUncalibratedRecHit::kGood) << std::endl;
  std::cout << "urh.checkFlag(EcalUncalibratedRecHit::kPoorReco) = "  <<  urh.checkFlag(EcalUncalibratedRecHit::kPoorReco) << std::endl;
  std::cout << "urh.checkFlag(EcalUncalibratedRecHit::kSaturated) = "  <<  urh.checkFlag(EcalUncalibratedRecHit::kSaturated) << std::endl;
  std::cout << "urh.checkFlag(EcalUncalibratedRecHit::kOutOfTime) = "  <<  urh.checkFlag(EcalUncalibratedRecHit::kOutOfTime) << std::endl;
  std::cout<<"urh.checkFlag(EcalUncalibratedRecHit::kLeadingEdgeRecovered) = "<<urh.checkFlag(EcalUncalibratedRecHit::kLeadingEdgeRecovered)<<std::endl;
  CPPUNIT_ASSERT(!urh.checkFlag(EcalUncalibratedRecHit::kGood));
  CPPUNIT_ASSERT(urh.checkFlag(EcalUncalibratedRecHit::kPoorReco));
  CPPUNIT_ASSERT(urh.checkFlag(EcalUncalibratedRecHit::kSaturated));
  CPPUNIT_ASSERT(urh.checkFlag(EcalUncalibratedRecHit::kOutOfTime));
  CPPUNIT_ASSERT(urh.checkFlag(EcalUncalibratedRecHit::kLeadingEdgeRecovered));
  CPPUNIT_ASSERT(outOfTimeEnergy_init ==  urh.outOfTimeEnergy());
  CPPUNIT_ASSERT(outOfTimeChi2_init ==  urh.outOfTimeChi2());


  std::cout << "setting EcalUncalibratedRecHit::kGood" << std::endl;
  urh.setFlagBit(EcalUncalibratedRecHit::kGood);// 
  print(urh.flags());
  std::cout << "urh.checkFlag(EcalUncalibratedRecHit::kGood) = "  <<  urh.checkFlag(EcalUncalibratedRecHit::kGood) << std::endl;
  std::cout << "urh.checkFlag(EcalUncalibratedRecHit::kPoorReco) = "  <<  urh.checkFlag(EcalUncalibratedRecHit::kPoorReco) << std::endl;
  std::cout << "urh.checkFlag(EcalUncalibratedRecHit::kSaturated) = "  <<  urh.checkFlag(EcalUncalibratedRecHit::kSaturated) << std::endl;
  std::cout << "urh.checkFlag(EcalUncalibratedRecHit::kOutOfTime) = "  <<  urh.checkFlag(EcalUncalibratedRecHit::kOutOfTime) << std::endl;
  std::cout<<"urh.checkFlag(EcalUncalibratedRecHit::kLeadingEdgeRecovered) = "<<urh.checkFlag(EcalUncalibratedRecHit::kLeadingEdgeRecovered)<<std::endl;
  CPPUNIT_ASSERT(urh.checkFlag(EcalUncalibratedRecHit::kGood));
  CPPUNIT_ASSERT(!urh.checkFlag(EcalUncalibratedRecHit::kPoorReco));
  CPPUNIT_ASSERT(!urh.checkFlag(EcalUncalibratedRecHit::kSaturated));
  CPPUNIT_ASSERT(!urh.checkFlag(EcalUncalibratedRecHit::kOutOfTime));
  CPPUNIT_ASSERT(!urh.checkFlag(EcalUncalibratedRecHit::kLeadingEdgeRecovered));
  CPPUNIT_ASSERT(outOfTimeEnergy_init ==  urh.outOfTimeEnergy());
  CPPUNIT_ASSERT(outOfTimeChi2_init ==  urh.outOfTimeChi2());


  
  std::cout<< "final value of outOfTimeEnergy = " << urh.outOfTimeEnergy() << std::endl;
  print(urh.flags());
  CPPUNIT_ASSERT(outOfTimeEnergy_init ==  urh.outOfTimeEnergy());

  std::cout<< "final value of outOfTimeChi2 = " << urh.outOfTimeChi2() << std::endl;
  print(urh.flags());
  CPPUNIT_ASSERT(outOfTimeChi2_init ==  urh.outOfTimeChi2());


}
