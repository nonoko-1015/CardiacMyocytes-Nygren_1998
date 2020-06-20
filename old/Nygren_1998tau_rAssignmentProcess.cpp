
#include "libecs.hpp"
#include "Process.hpp"

USE_LIBECS;

LIBECS_DM_CLASS( Nygren_1998tau_rAssignmentProcess, Process )
{

 public:

  LIBECS_DM_OBJECT( Nygren_1998tau_rAssignmentProcess, Process )
  {
    INHERIT_PROPERTIES( Process );


  }

  Nygren_1998tau_rAssignmentProcess()
  {
    // do nothing
  }



  virtual void initialize()
  {
    Process::initialize();

    tau_r  = getVariableReference( "tau_r" ).getVariable();
    V  = getVariableReference( "V" ).getVariable();

  }

  virtual void fire()
  {
    tau_r->setValue( 1 * (0.00350000*exp(-(pow(V->getValue()/30.0000, 2.00000)))+0.00150000) );

  }

 protected:

  Variable* tau_r;
  Variable* V;


};

LIBECS_DM_INIT( Nygren_1998tau_rAssignmentProcess, Process );
