
#include "libecs.hpp"
#include "Process.hpp"

USE_LIBECS;

LIBECS_DM_CLASS( Nygren_1998n_infinityAssignmentProcess, Process )
{

 public:

  LIBECS_DM_OBJECT( Nygren_1998n_infinityAssignmentProcess, Process )
  {
    INHERIT_PROPERTIES( Process );


  }

  Nygren_1998n_infinityAssignmentProcess()
  {
    // do nothing
  }



  virtual void initialize()
  {
    Process::initialize();

    n_infinity  = getVariableReference( "n_infinity" ).getVariable();
    V  = getVariableReference( "V" ).getVariable();

  }

  virtual void fire()
  {
    n_infinity->setValue( 1 * (1.00000/(1.00000+exp((V->getValue()-19.9000)/-12.7000))) );

  }

 protected:

  Variable* n_infinity;
  Variable* V;


};

LIBECS_DM_INIT( Nygren_1998n_infinityAssignmentProcess, Process );
