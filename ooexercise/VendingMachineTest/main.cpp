#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>

int main( int argc, char* argv[] ) {
  // �C�x���g�E�}�l�[�W���ƃe�X�g�E�R���g���[���𐶐�����
  CPPUNIT_NS::TestResult controller;

  // �e�X�g���ʎ��W���X�i���R���g���[���ɃA�^�b�`����
  CPPUNIT_NS::TestResultCollector result;
  controller.addListener( &result );

  // �u.�v�Ői�s�󋵂��o�͂��郊�X�i���A�^�b�`����
  CPPUNIT_NS::BriefTestProgressListener progress;
  controller.addListener( &progress );

  // �e�X�g�E�����i�[�Ƀe�X�g�Q��^���A�e�X�g����
  CPPUNIT_NS::TestRunner runner;
  runner.addTest( CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest() );
  runner.run( controller );

  // �e�X�g���ʂ�W���o�͂ɓf���o��
  CPPUNIT_NS::CompilerOutputter outputter( &result, CPPUNIT_NS::stdCOut() );
  outputter.write();

  return result.wasSuccessful() ? 0 : 1;
}