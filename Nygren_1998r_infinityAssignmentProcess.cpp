
#include "libecs.hpp"
#include "Process.hpp"

USE_LIBECS;

LIBECS_DM_CLASS( Nygren_1998r_infinityAssignmentProcess, Process )
{

 public:

  LIBECS_DM_OBJECT( Nygren_1998r_infinityAssignmentProcess, Process )
  {
    INHERIT_PROPERTIES( Process );


  }

  Nygren_1998r_infinityAssignmentProcess()
  {
    // do nothing
  }



  virtual void initialize()
  {
    Process::initialize();

    r_infinity  = getVariableReference( "r_infinity" ).getVariable();
    V  = getVariableReference( "V" ).getVariable();

  }

  virtual void fire()
  {
    r_infinity->setValue( 1 * (1.00000/(1.00000+exp((V->getValue()-1.00000)/-11.0000))) );

  }

 protected:

  Variable* r_infinity;
  Variable* V;


};

LIBECS_DM_INIT( Nygren_1998r_infinityAssignmentProcess, Process );
