
#include "libecs.hpp"
#include "Process.hpp"

USE_LIBECS;

LIBECS_DM_CLASS( Nygren_1998m_infinityAssignmentProcess, Process )
{

 public:

  LIBECS_DM_OBJECT( Nygren_1998m_infinityAssignmentProcess, Process )
  {
    INHERIT_PROPERTIES( Process );


  }

  Nygren_1998m_infinityAssignmentProcess()
  {
    // do nothing
  }



  virtual void initialize()
  {
    Process::initialize();

    m_infinity  = getVariableReference( "m_infinity" ).getVariable();
    V  = getVariableReference( "V" ).getVariable();

  }

  virtual void fire()
  {
    m_infinity->setValue( 1 * (1.00000/(1.00000+exp((V->getValue()+27.1200)/-8.21000))) );

  }

 protected:

  Variable* m_infinity;
  Variable* V;


};

LIBECS_DM_INIT( Nygren_1998m_infinityAssignmentProcess, Process );
