
#include "libecs.hpp"
#include "Process.hpp"

USE_LIBECS;

LIBECS_DM_CLASS( Nygren_1998p_a_infinityAssignmentProcess, Process )
{

 public:

  LIBECS_DM_OBJECT( Nygren_1998p_a_infinityAssignmentProcess, Process )
  {
    INHERIT_PROPERTIES( Process );


  }

  Nygren_1998p_a_infinityAssignmentProcess()
  {
    // do nothing
  }



  virtual void initialize()
  {
    Process::initialize();

    p_a_infinity  = getVariableReference( "p_a_infinity" ).getVariable();
    V  = getVariableReference( "V" ).getVariable();

  }

  virtual void fire()
  {
    p_a_infinity->setValue( 1 * (1.00000/(1.00000+exp((V->getValue()+15.0000)/-6.00000))) );

  }

 protected:

  Variable* p_a_infinity;
  Variable* V;


};

LIBECS_DM_INIT( Nygren_1998p_a_infinityAssignmentProcess, Process );
