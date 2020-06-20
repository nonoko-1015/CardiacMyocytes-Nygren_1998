
#include "libecs.hpp"
#include "Process.hpp"

USE_LIBECS;

LIBECS_DM_CLASS( Nygren_1998h_infinityAssignmentProcess, Process )
{

 public:

  LIBECS_DM_OBJECT( Nygren_1998h_infinityAssignmentProcess, Process )
  {
    INHERIT_PROPERTIES( Process );


  }

  Nygren_1998h_infinityAssignmentProcess()
  {
    // do nothing
  }



  virtual void initialize()
  {
    Process::initialize();

    h_infinity  = getVariableReference( "h_infinity" ).getVariable();
    V  = getVariableReference( "V" ).getVariable();

  }

  virtual void fire()
  {
    h_infinity->setValue( 1 * (1.00000/(1.00000+exp((V->getValue()+63.6000)/5.30000))) );

  }

 protected:

  Variable* h_infinity;
  Variable* V;


};

LIBECS_DM_INIT( Nygren_1998h_infinityAssignmentProcess, Process );
