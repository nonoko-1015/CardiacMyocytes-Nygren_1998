
#include "libecs.hpp"
#include "Process.hpp"

USE_LIBECS;

LIBECS_DM_CLASS( Nygren_1998tau_nAssignmentProcess, Process )
{

 public:

  LIBECS_DM_OBJECT( Nygren_1998tau_nAssignmentProcess, Process )
  {
    INHERIT_PROPERTIES( Process );


  }

  Nygren_1998tau_nAssignmentProcess()
  {
    // do nothing
  }



  virtual void initialize()
  {
    Process::initialize();

    tau_n  = getVariableReference( "tau_n" ).getVariable();
    V  = getVariableReference( "V" ).getVariable();

  }

  virtual void fire()
  {
    tau_n->setValue( 1 * (0.700000+0.400000*exp(-(pow((V->getValue()-20.0000)/20.0000, 2.00000)))) );

  }

 protected:

  Variable* tau_n;
  Variable* V;


};

LIBECS_DM_INIT( Nygren_1998tau_nAssignmentProcess, Process );
