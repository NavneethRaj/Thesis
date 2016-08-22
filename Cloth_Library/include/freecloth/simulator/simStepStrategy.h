#ifndef freecloth_sim_simStepStrategy_h
#define freecloth_sim_simStepStrategy_h

#ifndef freecloth_simulator_package_h
#include <freecloth/simulator/package.h>
#endif

#ifndef freecloth_resmgt_rcBase_h
#include <freecloth/resmgt/rcBase.h>
#endif

#ifndef freecloth_resmgt_rcShdPtr_h
#include <freecloth/resmgt/rcShdPtr.h>
#endif

FREECLOTH_NAMESPACE_START

////////////////////////////////////////////////////////////////////////////////
// FORWARD DECLARATIONS

class SimSimulator;

////////////////////////////////////////////////////////////////////////////////
/*!
 * \class SimStepStrategy freecloth/simulator/simStepStrategy.h
 * \brief Abstract base class for simulator stepping algorithms.
 * \pattern Strategy
 *
 * This is a base class for different strategies for stepping the cloth
 * simulator. The semantics of what forms a "step" are dependent upon the
 * concrete strategy chosen.
 *
 * In general a "step" can be broken down into three phases: a setup phase
 * (preSubSteps), repeated subStep calls until subStepsDone is true, and a
 * concluding phase (postSubSteps). After completion of postSubSteps, the
 * step may or may not have been successful.
 */
class SimStepStrategy : public RCBase
{
public:

    // ----- types and enumerations -----

    typedef SimSimulator Simulator;

    // ----- member functions -----

    explicit SimStepStrategy( const RCShdPtr<Simulator>& );

    virtual void step();

    virtual void rewind() = 0;
    virtual bool subStepsDone() const = 0;
    virtual void preSubSteps() = 0;
    virtual void subStep() = 0;
    virtual void postSubSteps() = 0;
    virtual void cancelStep() = 0;
    virtual bool inStep() const = 0;
    virtual bool stepSucceeded() const = 0;

protected:
    const RCShdPtr<Simulator> _simulator;
};

////////////////////////////////////////////////////////////////////////////////
// GLOBAL FUNCTIONS
//

FREECLOTH_NAMESPACE_END

#endif
