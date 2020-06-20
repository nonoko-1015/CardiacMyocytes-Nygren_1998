
#include "libecs.hpp"
#include "Process.hpp"

USE_LIBECS;

LIBECS_DM_CLASS( Nygren_1998s_sus_infinityAssignmentProcess, Process )
{

 public:

  LIBECS_DM_OBJECT( Nygren_1998s_sus_infinityAssignmentProcess, Process )
  {
    INHERIT_PROPERTIES( Process );


  }

  Nygren_1998s_sus_infinityAssignmentProcess()
  {
    // do nothing
  }



  virtual void initialize()
  {
    Process::initialize();

    s_sus_infinity  = getVariableReference( "s_sus_infinity" ).getVariable();
    V  = getVariableReference( "V" ).getVariable();

  }

  virtual void fire()
  {
    s_sus_infinity->setValue( 1 * (0.400000/(1.00000+exp((V->getValue()+20.0000)/10.0000))+0.600000) );

  }

 protected:

  Variable* s_sus_infinity;
  Variable* V;


};

LIBECS_DM_INIT( Nygren_1998s_sus_infinityAssignmentProcess, Process );
