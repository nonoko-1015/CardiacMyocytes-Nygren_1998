
#include "libecs.hpp"
#include "Process.hpp"

USE_LIBECS;

LIBECS_DM_CLASS( Nygren_1998d_L_infinityAssignmentProcess, Process )
{

 public:

  LIBECS_DM_OBJECT( Nygren_1998d_L_infinityAssignmentProcess, Process )
  {
    INHERIT_PROPERTIES( Process );


  }

  Nygren_1998d_L_infinityAssignmentProcess()
  {
    // do nothing
  }



  virtual void initialize()
  {
    Process::initialize();

    d_L_infinity  = getVariableReference( "d_L_infinity" ).getVariable();
    V  = getVariableReference( "V" ).getVariable();

  }

  virtual void fire()
  {
    d_L_infinity->setValue( 1 * (1.00000/(1.00000+exp((V->getValue()+9.00000)/-5.80000))) );

  }

 protected:

  Variable* d_L_infinity;
  Variable* V;


};

LIBECS_DM_INIT( Nygren_1998d_L_infinityAssignmentProcess, Process );
