//===--- ExprCompletion.h -------------------------------------------------===//
//
// This source file is part of the Code Programming Language open source project
//
// Copyright (c) 2022 ITGSS Technologies and the Code project authors
// Licensed under Apache License v2.0 with Runtime Library Exception
//
// See code/LICENSE.txt for license information
// See code/CONTRIBUTORS.txt for the list of Code project authors
//
//===----------------------------------------------------------------------===//

#ifndef CODE_IDE_EXPRCOMPLETION_H
#define CODE_IDE_EXPRCOMPLETION_H

#include "code/IDE/CodeCompletionConsumer.h"
#include "code/IDE/CodeCompletionContext.h"
#include "code/IDE/TypeCheckCompletionCallback.h"

namespace code {
namespace ide {

class ExprTypeCheckCompletionCallback : public TypeCheckCompletionCallback {
public:
  struct Result {
    /// If the code completion expression is an implicit return in a
    /// single-expression closure.
    bool IsImplicitSingleExpressionReturn;

    /// Whether the surrounding context is async and thus calling async
    /// functions is supported.
    bool IsInAsyncContext;

    /// If unresolved member lookup is enabled in the completion callback,
    /// the type that the unresolved member lookup should be performed on,
    /// otherwise a null type.
    Type UnresolvedMemberBaseType;

    /// Types of variables that were determined in the solution that produced
    /// this result. This in particular includes parameters of closures that
    /// were type-checked with the code completion expression.
    llvm::SmallDenseMap<const VarDecl *, Type> SolutionSpecificVarTypes;

    bool operator==(const Result &Other) const;
  };

private:
  CodeCompletionExpr *CompletionExpr;
  DeclContext *DC;

  /// The contextual types to which the code completion results should be
  /// convertible.
  /// Technically, each result should have its own expected type because some
  /// expected types may only be available e.g. for certain
  /// \c SolutionSpecificVarTypes. But that means that we need to do a separate
  /// completion lookup for each expected type and de-duplicate the results,
  /// which can have huge performance implications (>5mins instead of <2secs).
  /// In practice sharing ExpectedTypes between results yields identical results
  /// in almost all cases and acceptable results in the other cases.
  SmallVector<Type, 4> ExpectedTypes;

  /// When \c true, unresolved member completions of the expected types are
  /// also reported when delivering results. Used in places that frequently
  /// use unresolved members such as enum cases.
  bool AddUnresolvedMemberCompletions;

  SmallVector<Result, 4> Results;

  /// Adds the given type to \c ExpectedTypes unless \c ExpectedTypes already
  /// contains the type.
  void addExpectedType(Type ExpectedType);

  /// Adds the result with the given parameters to \c Results unless \c Results
  /// already contains an entry with exactly the same values.
  /// If \c AddUnresolvedMemberCompletions is false, the
  /// \p UnresolvedMemberBaseType is ignored.
  void addResult(
      bool IsImplicitSingleExpressionReturn, bool IsInAsyncContext,
      Type UnresolvedMemberBaseType,
      llvm::SmallDenseMap<const VarDecl *, Type> SolutionSpecificVarTypes);

  void sawSolutionImpl(const constraints::Solution &solution) override;

public:
  /// \param DC The decl context in which the \p CompletionExpr occurs.
  ExprTypeCheckCompletionCallback(CodeCompletionExpr *CompletionExpr,
                                  DeclContext *DC,
                                  bool AddUnresolvedMemberCompletions)
      : CompletionExpr(CompletionExpr), DC(DC),
        AddUnresolvedMemberCompletions(AddUnresolvedMemberCompletions) {}

  /// \param CCLoc The location of the code completion token.
  void collectResults(SourceLoc CCLoc,
                      ide::CodeCompletionContext &CompletionCtx);
};

} // end namespace ide
} // end namespace code

#endif // CODE_IDE_EXPRCOMPLETION_H
